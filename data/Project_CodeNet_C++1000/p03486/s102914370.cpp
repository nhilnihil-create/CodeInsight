#include <bits/stdc++.h>
using namespace std;

int main(){
    
    string s,t;
    cin >> s >> t;
    vector<char> s_sort(s.size()),t_sort(t.size());
    for(int i=0; i<s.size(); i++){
        s_sort.at(i)=s.at(i);
    }
    for(int i=0; i<t.size(); i++){
        t_sort.at(i)=t.at(i);
    }   

    sort(s_sort.begin(),s_sort.end());
    sort(t_sort.begin(),t_sort.end(),greater<>());

    if(s_sort<t_sort) cout << "Yes" << endl;
    else cout << "No" << endl;
}