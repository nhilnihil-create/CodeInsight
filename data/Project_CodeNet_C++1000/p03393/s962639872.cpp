#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isok = false;
string f(vector<bool> &isused, string start, string s, int phase){
    int i;
    if(phase >= start.length()-1) isok = true;
    if(phase < start.length()){
        i = start[phase]-'a';
    }else{
        i = 0;
    }
    string ans = "";
    for(; i < isused.size(); i++){
        if(ans != "") break;
        if(isused[i]) continue;
        isused[i] = true;
        s += (char)(i+'a');
        if(isok && s != start){
            ans = s;
            break;
        }
        ans = f(isused, start, s, phase+1);
        isused[i] = false;
        s.pop_back();
    }
    return ans;
}

int main(){
    string s;
    cin >> s;
    vector<bool> isused(26, false);
    string ans = f(isused, s, "", 0);
    if(ans == "") ans = "-1";
    cout << ans << endl;
    return 0;
}