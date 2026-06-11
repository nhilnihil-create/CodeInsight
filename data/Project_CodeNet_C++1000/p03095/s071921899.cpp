#include<cstdio>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>

#define ll long long
#define FOR(i,N) for(int i=0;i<(int)N;i++)
#define FORIN(i,a,b) for(int i=a;i<(int)b;i++)
#define ALL(x) (x).begin(),(x).end()
#define LAST(x) (x)[(x).size()-1]

using namespace std;

string to_hex(int x){
    stringstream ss;
    ss<<hex<<x;
    return ss.str();
}

string to_string(string s){
    return s;
}

template<class T>
string to_string(vector<T> v){
    string ret="{";
    FOR(i,v.size()-1){
        ret+=to_string(v[i])+",";
    }
    if(v.size()>0){
        ret+=to_string(LAST(v));
    }
    ret+="}";
    return ret;
}

void debug(){
    cerr<<endl;
}

template<class Head,class... Tail>
void debug(Head head,Tail... tail){
    cerr<<" "<<to_string(head);
    debug(tail...);
}

int main(){
    int N;
    cin>>N;
    string S;
    cin>>S;
    int list[26]={};
    FOR(i,S.size()){
        list[S[i]-'a']++;
    }
    ll sm=0;
    FOR(i,26){
        if(list[i]>0)sm=(sm+list[i]*sm+list[i])%1000000007;
    }
    cout<<sm<<endl;
    return 0;
}
