#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<list>

#define endl "\n"
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

int const num = 55555;

int main(){
    int n;
    cin>>n;
    bool a[num+1];
    bool ans[num+1];
    for(int i=0;i<=num;i++){
        a[i]=true;
        ans[i]=false;
    }

    for(int i=2;i*i<=num;i++){
        if(a[i] == false) continue;
        for(int j=2;i*j<=num;j++){
            if(a[i*j] == false) continue;
            a[i*j] = false;
        }
    }

    for(int i=2;i<=num;i++){
        if(i % 5 != 1) a[i] = false;
    }

    cout<<2<<" ";
    int i = 3;
    int ansnum = 1;
    while(ansnum < n){
        if(a[i]){
            cout<<i<<" ";
            ansnum++;
        }
        i++;
    }
    cout<<endl;
}