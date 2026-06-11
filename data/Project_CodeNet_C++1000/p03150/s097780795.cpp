#include <iostream>
using namespace std;
int main(){
    string s = "keyence";
    string t;
    cin >> t;
    if(s==t){
        puts("YES");
        return 0;
    }
    int n = t.size();
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            string tmp = "";
            for(int k=0; k<n; k++){
                if(i<=k && k<=j) continue;
                else tmp.push_back(t[k]);
            }
            if(tmp==s){
                puts("YES");
                return 0;
            }
        }
    }
    puts("NO");
    return 0;
}