#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    char a,b,c,d,sign[3];
    cin>>a>>b>>c>>d;
    int num[4];
    num[0]=a-'0';
    num[1]=b-'0';
    num[2]=c-'0';
    num[3]=d-'0';
    for(int bit=0;bit<(1<<3);++bit){
        int sum=num[0];
        rep(i,3){
            if(bit&(1<<i)){
                sum+=num[i+1];
                sign[i]='+';
            }
            else{
                sum-=num[i+1];
                sign[i]='-';
            }
        }
        if(sum==7){
            rep(j,3){
                cout<<num[j]<<sign[j];
            }
            cout<<num[3]<<"=7"<<endl;
            break;
        }
    }


    return 0;
}
