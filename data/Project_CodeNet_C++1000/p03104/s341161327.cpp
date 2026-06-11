#include <bits/stdc++.h>
using namespace std;
long long int a[45];
long long int b[45];
int main(){
    long long int A,B;
    cin >> A >> B;
        A--;
        long long int ans=0;
        for(long long int i=0;i<45;i++){
            if(i==0)a[0]=A%(1LL<<2);
            else a[i]=A%(1LL<<(i+1));
            if((1LL<<(i+1))>A)break;
        }
        for(long long int i=0;i<45;i++){
            if(i==0)b[0]=B%(1<<2);
            else b[i]=B%(1LL<<(i+1));
            if((1LL<<(i+1))>B)break;
        }
        long long int aa,bb;
        for(long long int i=0;i<45;i++){
            if(i==0){
            if(a[0]==1 || a[0]==2)aa=1;
            else aa=0;
            if(b[0]==1 || b[0]==2)bb=1;
            else bb=0;
            ans += (1<<0)*(aa^bb);
            }
            else{
                if(a[i]>=(1LL<<i))aa=(a[i]-(1LL<<i)+1)%2;
                else aa=0;
                if(b[i]>=(1LL<<i))bb=(b[i]-(1LL<<i)+1)%2;
                else bb=0;
                ans += (1LL<<i)*(aa^bb);
            }
        }
        cout << ans << endl;    
}