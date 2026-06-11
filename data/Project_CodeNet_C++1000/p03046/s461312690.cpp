#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <string>
#include <utility>
#include <iomanip>
#include <queue>
#include <algorithm>
#include<set>
#include<unordered_set>
using namespace std;
int root(int a);
bool is_same_set(int a,int b);
void unite(int a,int b);
long long int mpown(long long int m,long long int n);
int P[100001];
int main()
{
    long long int m;
    long long int k;
    cin >> m >> k;
    long long int pown = (1<<m);
    // cout << pown << endl;
    if(pown <= k){cout << -1 << endl;return 0;}
    
    if(m==0){
        if(k==0)cout << "0 0" << endl;
        else cout << -1 << endl;
        return 0;
    }
    else if(m==1){
        if(k==0)cout << "0 1 1 0" << endl;
        if(k==1)cout << -1 << endl;
    }
    else{
        for(long long int i=0;i<pown;i++){
            if(i==k)continue;
            cout << i << " ";
        }
        cout << k << " ";
        for(long long int i=pown-1;i>=0;i--){
            if(i==k)continue;
            cout << i << " ";
        }
        cout << k << endl;
    }
    return 0;

}
int root(int a){
    if(P[a]==a)return a;
    return (P[a]=root(P[a]));
}
bool is_same_set(int a,int b){
    return root(a)==root(b);
}
void unite(int a,int b){
    if(!is_same_set(a,b)) P[root(a)]=root(b);
}
long long int mpown(long long int m,long long int n){
    if(n==0)return 1;
    if(n==1)return m;
    long long int temp=mpown(m,n/2);
    return temp*temp*(n&1?m:1);
}