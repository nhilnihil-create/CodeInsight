#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
int main(void){
    string s;
    cin>>s;
    sort(s.begin(), s.end());
    do{
        if(s == "abc"){
            cout<<"Yes"<<endl;
            return 0;
        }
    }while(next_permutation(s.begin(), s.end()));
    cout<<"No"<<endl;
    return 0;
}