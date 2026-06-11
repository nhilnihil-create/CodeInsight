#include<bits/stdc++.h>
using namespace std;

#define sup ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int N = 305;

double p[N][N][N], ev[N][N][N];

int main()
{
	sup;
    
    int n ;
    cin >> n;

    vector<int> cnt(4);

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ++cnt[x];
    }

    p[cnt[1]][cnt[2]][cnt[3]] = 1;

    for(int c = n; c >= 0; c--) {
        for(int b = n; b >= 0; b--) {
            for(int a = n; a >= 0; a--) {

                if(a == 0 && b == 0 && c == 0)
                    continue;

                int k = a + b + c;
                if(k > n)
                    continue;

                double p_waste = (double) (n - k) / n;
                double ev_waste = p_waste / (1 - p_waste) + 1;
                ev[a][b][c] += p[a][b][c] * ev_waste;

                if(a) {
                    double p_go = (double) a / k;
                    p[a - 1][b][c] += p[a][b][c] * p_go;
                    ev[a - 1][b][c] += ev[a][b][c] * p_go;
                }

                if(b) {
                    double p_go = (double) b / k;
                    p[a + 1][b - 1][c] += p[a][b][c] * p_go;
                    ev[a + 1][b - 1][c] += ev[a][b][c] * p_go;
                }

                if(c) {
                    double p_go = (double) c / k;
                    p[a][b + 1][c - 1] += p[a][b][c] * p_go;
                    ev[a][b + 1][c - 1] += ev[a][b][c] * p_go;
                }
            }
        }
    }

    cout << setprecision(12) << fixed; 
    cout << ev[0][0][0] << endl;

    return 0;
}