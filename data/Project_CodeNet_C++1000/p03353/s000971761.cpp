#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;

int main(){
    string s;
    int k;
    cin>>s>>k;
    map<string,int> maps;
    for(int i=1;i<=k;i++){
        for(int j=0;i+j<=s.length();j++){
            string str=s.substr(j,i);
            maps[str]++;
        }        
    }
    int index=0;
    for(const auto& item:maps){
        index++;
        if(index==k){
            cout<<item.first<<endl;
            return 0;
        }
    }
}