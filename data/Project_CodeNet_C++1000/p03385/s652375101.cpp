#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <math.h>
#include <string>
#include <numeric>
#include <queue>
#define ll long long
#define rep(i,n) for(ll i=0;i<n;++i)
#define rep1(i,n) for(ll i=1;i<n;++i)
#define mrep(i,n) for(ll i=n;i>=0;--i)
#define all(a) (a).begin(),(a).end()
#define vl vector<ll>
#define vvl vector<vector<ll> >
#define vb vector<bool>
#define vvb vector<vector<bool> >
#define pl pair<ll,ll>
#define inf 1001001001001001000
#define mod 1000000007
#define pi 3.1415926535
using namespace std;

template<typename T>
struct Graph{
    vector<T> nodes;
    map<T,vector<pair<T,ll> > > nexts;
    Graph(ll n,T initial){
        nodes.resize(n,initial);
    }
    Graph(ll n){
        nodes.resize(n);
    }
    Graph(vector<T> &a):nodes(a){}
    Graph(){}
    void add_edge(T &s,T &e,ll c){
        this->nexts[s].push_back({e,c});
    }
    map<T,ll> dijkstra(T &s){
        map<T,ll> dist;
        for(T tmp:this->nodes){
            dist[tmp] = inf;
        }
        priority_queue<pair<ll,T>,vector<pair<ll,T> >,greater<pair<ll,T> > > q;
        q.push({0,s});
        dist[s] = 0;
        while(q.empty() == false){
            pair<ll,T> now = q.top();
            q.pop();
            if(now.first > dist[now.second]) continue;
            dist[now.second] = now.first;
            for(pair<T,ll> next:this->nexts[now.second]){
                if(now.first + next.second < dist[next.first]){
                    dist[next.first] = now.first+next.second;
                    q.push({dist[next.first],next.first});
                }
            }
        }
        return dist;
    }
};

struct Node{
    ll x;
    Node(ll a): x(a){}
    Node(): x(1){}
    bool operator<(const Node &b)const{
        return this->x < b.x;
    }
};

int main(void){
    string s;
    cin>>s;
    sort(all(s));
    if(s == "abc") cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}