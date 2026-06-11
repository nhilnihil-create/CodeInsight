#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <set>
//#inlcude<stringstream>
#define ll long long
#define MODD 1000000007
using namespace std;
ll arr[1000000]={0};
ll brr[1000000]={0};
int main() {
    //
    ll a , b;cin >>a>>b;
    int flag=1;
    a--,b--;
    cout<<100<<" "<<100<<endl;
    for(int i=1;i<=50;i++){
        for(int j=1;j<=100;j++){
           if(i%2==0&&j%2==0&&a){
                a--;
                cout<<".";
           }
           else cout<<"#";
        }
       cout<<endl;
    }
    for(int i=1;i<=50;i++){
        for(int j=1;j<=100;j++){
            if(i%2==0&&j%2==0&&b){
                b--;
                cout<<"#";
           }
           else cout<<".";
        }
        cout<<endl;

    }
    return 0;
}
