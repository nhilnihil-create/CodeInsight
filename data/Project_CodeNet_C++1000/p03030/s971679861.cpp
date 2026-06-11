#include<iostream>
#include<vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

bool myless(pair<pair<string, int>, int> l, pair<pair<string, int>, int> r){
    if(l.first.first != r.first.first){
        return l.first.first < r.first.first;
    }else{
        return l.first.second > r.first.second;
    }
}

int main(){
    int n;
    cin >> n;
    vector<pair<pair<string, int >, int > > v;
    for(int i = 0; i < n; i++){
        string s;
        int point;
        cin >> s >> point;
        v.push_back(make_pair(make_pair(s,point), i));
    }
    sort(v.begin(), v.end(), myless);
    for(int i = 0; i < n; i++){
        cout << v[i].second+1 << endl;
    }
    


}