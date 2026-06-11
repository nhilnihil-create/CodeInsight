#include "./bits/stdc++.h"
using namespace std;
typedef long long ll;
int N;

int main(){
    cin>>N;
    int h[N];
    int ans=0;
    int x=0;
    int b;

    for(int i=0;i<N;i++){
        cin >> h[i];
    }

    for(int i=0;i<N;i++){
        if(x < h[i]){
            ans+=h[i]-x;
            x=h[i];
        }else{
            x=h[i];
        }
    }
    cout << ans << endl;

    return 0;
}