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
int P[100001];
int main()
{
    int n,m;
    cin >> n >> m;
    
    for(int i=0;i<n;i++){
        P[i]=i;
    }
    int x,y,z;
    for(int i=0;i<m;i++){
        cin >> x >> y >> z;
        x--;y--;
        unite(x,y);
    }
    unordered_set<int> shima;
    for(int i=0;i<n;i++){
        shima.insert(root(P[i]));
    }
    cout << shima.size() << endl;

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