#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
        if(a==0)return b;
        else return gcd(b%a,a);
}

int main(){
        vector<int> a(3);
        cin>>a[0]>>a[1]>>a[2];
        sort(a.begin(),a.end() ) ;
        if(a[2] == a[0] ) {
                cout<<"Yes"<<endl;
        }else{
                cout<<"No"<<endl;
        }

        return 0;
}
       