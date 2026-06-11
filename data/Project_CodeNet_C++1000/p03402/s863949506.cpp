#include <bits/stdc++.h>
#define ll long long
#define rep(X,N) for(ll X = 0; X < (N); X++)
#define bitrep(X,N) for(ll X = 0; X < (1 << (N)); X++)
#define PI (acos(-1.0))
#define sorta(V) sort(V.begin(), V.end())
#define pback push_back
#define mpair make_pair
#define MODN 1000000007
#define ALL(V) (V).begin(),(V).end() 
#define CERR if(false) cerr

using namespace std;


int main(){

    int a,b;
    cin >> a >> b;

    int X = 100;
    int Y = 100;

    vector<string> ans;

    rep(i,Y){
        string tmp;

        if(i < Y / 2){
            rep(j,X){
                tmp.pback('#');
            }
        }else{
            rep(j,X){
                tmp.pback('.');
            }
        }

        ans.pback(tmp);
    }

    a--;
    b--;

    int x = 1;
    int y = 1;

    while(a > 0){
        ans[y][x] = '.';

        x = x + 2;

        if(x == X - 3){
            x = 1;
            y = y + 2;
        }
        a--;
    }

    x = 1;
    y = Y / 2 + 1;

    while(b > 0){
        ans[y][x] = '#';

        x = x + 2;

        if(x == X - 3){
            x = 1;
            y = y + 2;
        }
        b--;
    }

    cout << Y << " " << X << endl;

    rep(i,Y){
        cout << ans[i] << endl;
    }


    return 0;
}