#include <bits/stdc++.h>
using namespace std;
using ll = long long;


bool lamp_check(bitset<10> s,int n,int m,vector<vector<int>> &array,vector<int> &p){
    //cout << s << endl;
    for(int i=0;i<m;i++){
        //cout << i << endl;
        int count = 0;
        for(int j=0;j<(int)array.at(i).size();j++){
            int num = array.at(i).at(j);
            if(s.test(num)){
                count++;
            }
        }
        if(count % 2 != p.at(i)) return false;
    }
    return true;
}


int main(){
 int n,m;
 cin >> n >> m;
 vector<vector<int>> switch_array(m);
 vector<int> p(m);
 for(int i=0;i<m;i++){
     int k;
     cin >> k;
     for(int j=0;j<k;j++){
         int l;
         cin >> l;
         switch_array.at(i).push_back(l-1);
     }
 }
 
 for(int i=0;i<m;i++) cin >> p.at(i);
 int c = 0;
 for(int tmp=0; tmp < (1 << n); tmp++){
     bitset<10> s(tmp);
     if(lamp_check(s,n,m,switch_array,p)){
         c++;
     }
 }
 cout << c << endl;
}