#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <functional>
#include <map>
#include <string>
using namespace std;
#define INF 1000000000;
#define MOD 1000000007;
typedef long long int ll;
int main(void){
    string s;
    cin>>s;
    int len=s.size();
    int cnt=0;
    for(auto c:s){
        if(c=='o')cnt++;
    }   
    if(cnt+15-len>=8){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}