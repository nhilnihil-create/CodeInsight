#include<bits/stdc++.h>

#define reps(i,f,n) for(int i = f; i < n; ++i)
#define rep(i,n) reps(i,0,n)

using namespace std;

int main(void){
    string a;
    int n;
    int x = 0;
    int y = 0;


    cin >> n;
    cin >> a;

    rep(i, n){
        if(a[i] == 'R'){
            x++;
        }else{
            y++;
        }
    }


    if(x > y){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}
