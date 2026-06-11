#include <iostream>
using namespace std;
typedef long long ll;
ll n,cnt=1;
string s;
int main(void){
    cin>>s;
    n=s.size();
    if(n==2&&s=="10"){
        cout<<"1 2"<<endl;
        return 0;
    }
    if(s[n-1]=='1'||s[0]=='0'){
        cout<<-1<<endl;
        return 0;
    }
    for(int i=0;i<(n-1)/2;i++){
        if(s[i]!=s[n-i-2]){
            cout<<-1<<endl;
            return 0;
        }
    }
    for(int i=0;i<n-1;i++){
        cout<<cnt<<" "<<i+2<<endl;
        if(s[i]=='1'){
            cnt=i+2;
        }
    }
}
