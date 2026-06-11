#include<bits/stdc++.h>
using namespace std;
#define int long long
//#undef int
#define mk make_pair
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
#define mod 1000000007

int N;
char s[1000006];
int Q, k[100];
int d[1000006], m[1000006];

signed main()
{
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> s[i];
        if(s[i] == 'D'){
            d[i]++;
        }
        else if(s[i] == 'M'){
            m[i]++;
        }
        d[i] += d[i - 1];
        m[i] += m[i - 1];
    }
    cin >> Q;
    for(int i = 0; i < Q; i++){
        cin >> k[i];
    }
    for(int i = 0; i < Q; i++){
        int K = k[i];
        int l = 1;
        int dm = 0, dmc = 0;
        for(int j = 1; j <= N; j++){
            if(j - l >= K && l < N){
                if(s[l] == 'D'){
                    dm -= (m[j - 1] - m[l - 1]);
                }
                l++;
            }
            if(s[j] == 'M'){
                dm += (d[j - 1] - d[max(j - K, 0ll)]);
            }
            else if(s[j] == 'C'){
                dmc += dm;
            }
        }
        cout << dmc << endl;
    }

    return 0;
}

/*

*/
