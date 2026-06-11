#include <iostream>
#include <vector>
#include <string>
using namespace std;
long long gcd(long long a,long long b){
    if(a<b) swap(a,b);
    while(a%b!=0){
        swap(a,b);
        b%=a;
    }
    return b;
}
bool judge(long long a,long long b,long long g){
    if(a>b) return false;
    if(b-a+1>=g) return true;
    if(a%g>b%g) return true;
    if(a%g==0) return true;
    else return false;
}
int main(){
    int q;
    cin >> q;
    vector<string> ans;
    long long a,b,c,d;
    for(int i = 0;i<q;i++){
        cin >> a >> b >> c >> d;
        if(judge(a-b+1,a-c-1,gcd(b,d))||a<b||b>d) ans.push_back("No");
        else ans.push_back("Yes");
    }
    for(int i = 0;i<ans.size();i++){
        cout << ans[i] << endl;
    }
}