#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    bool first_stand;
    if(s.at(0)=='1') first_stand=true;
    else first_stand = false;
    vector<int> people;
    int cnt=1;
    for(int i=1; i<n; i++){
        if(s.at(i) != s.at(i-1)){
            people.push_back(cnt);
            cnt=1;
        }
        else cnt++;
    }
    people.push_back(cnt);
    for(int i=1;i<people.size(); i++){
        people.at(i)+=people.at(i-1);
    }
    int ps=people.size();
    if(first_stand){
        int cnt=1;
        int ans = people.at(min(ps-1, 2*k));
        while(cnt<ps){
            int result;
            result = people.at(min(ps-1,cnt+2*k+1)) - people.at(cnt);
            cnt+=2;
            ans = max(ans,result);
        }
        cout << ans << endl;
    }
    else{
        int cnt=0;
        int ans=people.at(min(ps-1, 2*k-1));
        while(cnt<ps){
            int result;
            result = people.at(min(ps-1,cnt+2*k+1)) - people.at(cnt);
            cnt+=2;
            ans = max(ans,result);
        }
        cout <<ans << endl;
    }
}
