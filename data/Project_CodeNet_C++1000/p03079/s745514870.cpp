#include<iostream>
#include<math.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;

int main(){
    int a,b,c;
    cin>>a>>b>>c;

    if(a == b && b==c){
        if(a==c){
            cout<<"Yes";
            return 0;
        }
    }
    cout<<"No";
}