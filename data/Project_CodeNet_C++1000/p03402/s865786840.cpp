#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;

int main(){
    int a,b;
    cin>>a>>b;
    cout<<100<<" "<<100<<endl;
    for(int i=0;i<49;i++){
        for(int j=0;j<100;j++){
            if(a>1&&i%2==0&&j%2==0){
                --a;
                cout<<'.';
            }
            else{
                cout<<'#';
            }
        }
        cout<<endl;
    }
    for(int i=0;i<100;i++){
        cout<<'#';
    }
    cout<<endl;
    for(int i=0;i<100;i++){
        cout<<'.';
    }
    cout<<endl;
    for(int i=0;i<49;i++){
        for(int j=0;j<100;j++){
            if(b>1&&i%2==0&&j%2==0){
                --b;
                cout<<'#';
            }
            else{
                cout<<'.';
            }
        }
        cout<<endl;
    }
}
