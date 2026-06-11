#include <bits//stdc++.h>
#define rep(i,n) for(int i = 0;i < n;i++)
using namespace std;
typedef long long ll;

int main(){
    int n,a,g=0;
    cin >> n;
    rep(i,n){
        cin >> a;
        if(a%2==0)g++;
    }
    cout << pow(3,n)-pow(2,g) << endl;
    return 0;
}