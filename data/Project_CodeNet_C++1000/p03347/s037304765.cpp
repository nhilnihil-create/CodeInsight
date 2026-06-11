#include<bits/stdc++.h>

using namespace std;

const int N=3e5+500;

int q[N];

int main(){
    int a;
    long long r=0;
    cin >> a;
    int mg=0;
    for (int i=0 ; i<a ; i++){
        cin >> q[i];
        if (q[i] > i){
            mg=1;
        }
    }
    if (mg==1){
        cout << -1;
        return 0;
    }
   // cout << '\n';
    if (q[0]>0){
        cout << -1;
        return 0;
    }
    int w=0;
    for (int i=a-1 ; i>0 ; i--){
        int e=q[i];
        if (q[i-1] == e-1){
           if (w==0){
                r+=e;
                w=2;
                //cout << r << " "<< q[i-1]<<"\n";
           }

        }
        else if (q[i-1]==q[i]){
            r+=e;
        }
        else if (q[i-1] > q[i]){
            if (w==0){
               r+=e;
            }
            w=0;
        }
        else{
            cout << -1;
            return 0;
        }
    }
    cout << r;













}


