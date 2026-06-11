#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> v;
pair<int,int> p;
map<int,int> m;
deque<int> d;
int main(void){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cin>>n;
int x[9]={111,222,333,444,555,666,777,888,999};
for(int i=0;i<9;i++)
    if(x[i]>=n){
        cout<<x[i]<<endl;
        break;}
return 0;
}
