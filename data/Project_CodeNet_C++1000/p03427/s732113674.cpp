#include<iostream>
#include<math.h>
#include<cstring>
#include<vector>
#include<map>

typedef long long ll;

using namespace std;

#define rep(i,n) for(i=0;i<n;i++)
int main(){
    int i;
    char n[100];
    cin>>n;
    int max=0;
    int cnt=(int)strlen(n);
    int t=0;
    if(cnt==1){
        cout<<n<<endl;
        return 0;
    }
    rep(i,cnt){
        if(n[i]=='9')
            t++;
    }
    if(t==cnt){
        cout<<9*cnt<<endl;
        return 0;
    }else if(t==cnt-1 && n[0]!='9'){
        cout<<9*(cnt-1)+(int)(n[0]-'0')<<endl;
        return 0;
    }
    max=(cnt-1)*9;
    for(i=1;i<=10;i++){
        if((int)(n[0]-'0')<i){
            max+=(int)(n[0]-'0')-1;
            break;
        }
    }
    cout<<max<<endl;
}
