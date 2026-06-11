#include<bits/stdc++.h>
using namespace std;

const int maximum = 305;
double p[maximum][maximum][maximum];
double ev[maximum][maximum][maximum];

int main() {
    int n;
    cin>>n;
    vector<int> cnt(4);
    for(int i = 0; i < n; ++i) {
        int x;
        cin>>x;
        ++cnt[x];
    }

    p[cnt[1]][cnt[2]][cnt[3]] = 1;

    for(int c = cnt[3]; c >= 0; --c) {
        for(int b = cnt[2] + cnt[3]; b >= 0; --b) {
            for(int a = n; a >= 0; --a) {

                if(a == 0 && b == 0 && c == 0) {
                    continue;
                }
                if(a + b + c > n) {
                    continue;
                }

                double p_waste = (double) (n - (a + b + c)) / n;
                double ev_waste = p_waste / (1 - p_waste) + 1;

                ev[a][b][c] += ev_waste * p[a][b][c];

                if(a != 0) {
                    double prob_next = (double) a / (a + b + c);
                    p[a-1][b][c] += p[a][b][c] * prob_next;
                    ev[a-1][b][c] += ev[a][b][c] * prob_next;
                }
                if(b != 0) {
                    double prob_next = (double) b / (a + b + c);
                    p[a+1][b-1][c] += p[a][b][c] * prob_next;
                    ev[a+1][b-1][c] += ev[a][b][c] * prob_next;
                }
                if(c != 0) {
                    double prob_next = (double) c / (a + b + c);
                    p[a][b+1][c-1] += p[a][b][c] * prob_next;
                    ev[a][b+1][c-1] += ev[a][b][c] * prob_next;
                }
            }
        }
    }
    printf("%.10f\n", ev[0][0][0]);

    return 0;
}

