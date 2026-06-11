#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ans=0;
    for(int i=0;i<n/2+n%2;i++){
        int a=i+1,b=n-a;
        string aa=to_string(a),bb=to_string(b);
        int awa=0,bwa=0,tmp=0;
        for(int j=0;j<aa.size();j++){
            awa += aa[j] -'0';
        }
        for(int j=0;j<bb.size();j++){
            bwa += bb[j] -'0';
        }
        tmp = awa + bwa;
        if(i==0)ans=tmp;
        if(ans>tmp)ans=tmp;
    }
    cout << ans << endl;
    return 0;
}