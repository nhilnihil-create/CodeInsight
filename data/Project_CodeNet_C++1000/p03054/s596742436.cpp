#include <bits/stdc++.h>
#define NMAX 200005
#define ll long long int

using namespace std;

ll n, m, lg, sx, sy, maxim, outborder, antioutborder, i, sxx, syy;
char sir[NMAX], sir2[NMAX], aux;

int main(){
    cin >> n >> m >> lg;
    cin >> sx >> sy;
    cin.get(aux);
    cin.getline(sir, NMAX, '\n');
    cin.getline(sir2, NMAX, '\n');
    lg = strlen(sir);

    sxx = sy;

    for(i=0; i<lg; ++i){
        if(sir[i] == 'L')
            --sxx;
            if(sxx <= 0){
                cout << "NO\n";
                return 0;
            }
        if(sir2[i] == 'R' && sxx < m)
            ++sxx;

        }

    maxim = -1; sxx = sy;
    outborder = antioutborder = 0;

    for(i=0; i<lg; ++i){
        if(sir[i] == 'R')
            ++sxx;
             if(sxx > m){
                cout << "NO\n";
                return 0;
                }
        if(sir2[i] == 'L' && sxx > 1)
            --sxx;

        }

    maxim = -1; syy = sx;
    outborder = antioutborder = 0;


    for(i=0; i<lg; ++i){
        if(sir[i] == 'U')
            --syy;
             if(syy <= 0){
                cout << "NO\n";
                return 0;
                }
        if(sir2[i] == 'D' && syy < n)
            ++syy;

        }

    maxim = -1; sxx = sy; syy = sx;
        outborder = antioutborder = 0;


for(i=0; i<lg; ++i){
        if(sir[i] == 'D')
            ++syy;
            if(syy > n){
            cout << "NO\n";
        return 0;
            }
        if(sir2[i] == 'U' && syy > 1)
            --syy;

        }


    cout << "YES\n";
    return 0;
}
