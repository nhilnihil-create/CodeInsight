#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;


int main(){
    int N,Q;
    cin >> N >> Q;
    
    string s;
    cin >> s;
    
    //vector<int> AC;
    //AC.push_back(0);
    int ac=0;
    int count=0;
    vector<int> AC_count(N,0);
    
    for(int i=0; i< s.size()-1; i++){
        if(s[i]=='A' && s[i+1]=='C'){
            count++;
        }
        AC_count[i+1] = count;
    }
    

    int i,r;
    //int ans_count;
    rep(z,Q){
        cin >> i >> r;
        cout << AC_count[r-1] - AC_count[i-1] << endl;
    }
    
    /*
    for(int x: AC_count){
        cout << x << " ";
    }
    */
    /*
    int num = s.find("AC"); 
    //cout << num << endl;
    
    while(num != string::npos){
        
        num = s.find("AC");
        AC.push_back(num + count + 1);
        
        s = s.substr(num + 2);
        count += num + 2;
        ac++;
        num = s.find("AC");
        
        //cout << num << endl;
        //cout << s << endl;
        //cout << "while1" << endl;
        
        
    }
    
    vector<int> AC_count(N,0);
    //int ans_count=0;
    for(int x: AC){
        for(int i=0; i<=N; i++){
            if(i >= x){
                AC_count[i]++;
            }
        }
    }
    */
    
    /*
    int i,r;
    int ans_count;
    rep(z,Q){
        cin >> i >> r;
        ans_count = 0;
        for(int x:AC){
            if(i<=x && x <= r-1){
                ans_count++;
            }
        }
        cout << ans_count << endl;
    }
    */
    
    
    
}
