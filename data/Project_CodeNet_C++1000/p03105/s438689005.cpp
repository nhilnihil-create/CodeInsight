#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <utility>
#include <iomanip>
#include <queue>
#include <set>
#include <numeric>
#include <unordered_set>

#define rep(i,n) for(int i=0;i< (n);++i)
typedef long long ll;

using namespace std;


int main(){
    int A,B,C;
    cin>>A>>B>>C;
    
    int  a=B/A;
    
    if(a<C){
        cout<<a<<endl;
    }else{
        cout<<C<<endl;
    }

}