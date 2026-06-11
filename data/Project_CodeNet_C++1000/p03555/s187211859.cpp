#include<iostream>
#include<vector>
#include<set>
#include<string>
typedef long long int lli;
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> v;
    vector<string> v1;
    
    string s1;
    string s2;
    
    cin >> s1;
    cin>>s2;
    v.push_back(s2);
    reverse(s1.begin(), s1.end());
    v1.push_back(s1);
   // cout<<s1<<"\n";
   if(v==v1){
        cout<<"YES"<<"\n";
    }else{
        cout<<"NO"<<"\n";
    }
    return 0;
}

//100 >1000
//10000 > 1000000