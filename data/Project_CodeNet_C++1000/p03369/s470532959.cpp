#include <bits/stdc++.h>
using namespace std;
int main(){
    string S;
    cin>>S;
    int cnt=count(S.cbegin(),S.cend(),'o');
    cout<<(700+cnt*100)<<endl;
}
