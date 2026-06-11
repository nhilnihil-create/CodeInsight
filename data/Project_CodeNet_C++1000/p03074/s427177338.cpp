#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n,k;
    string s;
    cin>>n>>k>>s;
    
    vector<int> line1 = {0};
    vector<int> line0;
    
    if(s[0]=='1'){
        line1[line1.size()-1]++;
    }else{
        line0.push_back(1);
    }
    
    for(int i=1; i<n; i++){
        if(s[i]=='1'&&s[i-1]=='1'){
            line1[line1.size()-1]++;
        }else if(s[i]=='1'&&s[i-1]=='0'){
            line1.push_back(1);
        }else if(s[i]=='0'&&s[i-1]=='1'){
            line0.push_back(1);
        }else if(s[i]=='0'&&s[i-1]=='0'){
            line0[line0.size()-1]++;
        }
    }
    if(line1.size()==line0.size())
        line1.push_back(0);
    /*
    for(int i : line1){
        cout << i<< endl;
    }
    for(int i : line0){
        cout << i<< endl;
    }
    */
    
    int kmax = line0.size();//line1.size() - 1;
    if(k>=kmax){
        cout << (int)s.size() << endl;
        return 0;
    }
    
    int now = line1[0];
    
    for(int i=0; i<k; i++){
        now += line1[i+1] + line0[i];
    }
    int ans = now;
    int j = k;
    
    while(j<kmax){
        now -= line1[j-k] + line0[j-k];
        now += line1[j+1] + line0[j];
        j++;
        ans = max(ans, now);
    }
    
    cout << ans << endl;
}