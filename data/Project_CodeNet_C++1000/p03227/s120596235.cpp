#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int,int> P;

int main() {
    int i,j,n,p,q,temp;
    int t=0;
    int flag=0;
    string s;
    cin>>s;
    int size=s.size();
    if(size==2)cout<<s;
    else{
        reverse(s.begin(),s.end());
        cout<<s;
    }
    return 0;
}
