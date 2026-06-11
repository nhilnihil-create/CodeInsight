#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define vec(j,n) vector<int>(j(n))
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main(){
    int s;
    cin >> s;
    vector<int>aa(1000009);
    aa.at(0)=s;
    for(int i=0;i<1000009;i++){
        if(aa.at(i)%2 == 0){
        aa.at(i+1) = aa.at(i) / 2;
        }else{
        aa.at(i+1) = 3 * aa.at(i) + 1;
        }
        for(int j=0;j < i + 1 ;j++){
            if(aa.at(i+1)==aa.at(j)){
                cout << i + 2 << endl;
                return 0;
            }
        }
    }
    return 0;
}