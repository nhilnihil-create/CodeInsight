#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define vec(j,n) vector<int>(j(n))
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main(){
    int n ,x;
    cin >> n >> x;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin >> a.at(i);
    }
    sort(a.begin(),a.end());
    int count=0;
    for(int i=0;i<n;i++){
        x -= a.at(i);
        if(x<0){
            cout << count << endl;
            return 0;
        }
        count ++;
    }
    if(x > 0){
        cout << count - 1 << endl;
    }else{
        cout << count << endl;
    }
    return 0;
}