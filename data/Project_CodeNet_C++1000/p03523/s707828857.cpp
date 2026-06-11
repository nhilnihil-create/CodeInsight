#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include <bitset>
#include<math.h>
using namespace std;
#define INF 10000000
#define MOD 1000000007
typedef long long ll;
typedef pair<ll,int> P;

int st[3][40];

int main(){
    string ans[16]={"AKIHABARA","KIHABARA","AKIHBARA","AKIHABRA","AKIHABAR","AKIHABR","AKIHBAR","AKIHBRA","KIHABAR","KIHBARA","AKIHBR","KIHABR","KIHBAR","KIHBRA","KIHBR"};
    string s;
    cin>>s;
    for(int i=0;i<16;i++){
        if(ans[i]==s){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}
