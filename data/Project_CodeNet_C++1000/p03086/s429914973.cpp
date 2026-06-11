#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main(void){
    string s;
    cin >> s;
    string T = "ATCG";
    int ans = 0,count=0;
    for(int i=0;i<s.size();i++){
        bool isATCG = false;
        for(int j=0;j<T.size();j++){
            if(s[i] == T[j]) isATCG = true;
        }
        if(!isATCG){
            count = 0;
        }else{
            count++;
            ans = max(count,ans);
        }
    }

    cout << ans << endl;
	return 0;
}