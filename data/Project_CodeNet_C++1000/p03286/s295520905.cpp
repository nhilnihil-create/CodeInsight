#include<bits/stdc++.h>
using namespace std;
int main(){
    long int n;
    cin >> n;
    if(n==0)cout << "0" << endl;
    else{
    string S;
    long int i=0;
    long int tmp=2;
    long int hugo = 1;
    while(n!=0L){
        if(n%tmp!=0){
            S.push_back('1');
            n-=((tmp/2)*hugo);
        }
        else S.push_back('0');
        i++;
        hugo*=-1;
        tmp*=2;
    }
    for(int j=S.length()-1;j>=0;j--)cout << S[j];
    cout << endl;
    }
}