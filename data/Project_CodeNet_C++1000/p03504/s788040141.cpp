#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define repn(i, n) for(int i = 1; i <= n; i++)
#define repr(i, n) for(int i = n-1; i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define lint long long

struct event{
    int t, f, c;
};

vector<event> E;
int rec[30];
bool used[30];

bool comp(const event& x, const event& y){
    if(x.t != y.t) return x.t < y.t;
    if(x.f != y.f) return x.f < y.f;
    return x.c < y.c;
}

int find_available(int ch){
    rep(i, 30){
        if(rec[i] == ch + 100) return i;
    }
    rep(i, 30){
        if(rec[i] == -1) return i;
    }
    return -1;
}

int find_recording(int ch){
    rep(i, 30){
        if(rec[i] == ch) return i;
    }
    return -1;
}

int main(){
    int n, c; cin >> n >> c;
    memset(rec, -1, sizeof(rec));

    rep(i, n){
        int s, t, ch; cin >> s >> t >> ch; ch--;
        E.push_back(event{s, 1, ch});
        E.push_back(event{t, 0, ch});
        E.push_back(event{t+1, -1, ch});
    }
    sort(all(E), comp);

    rep(i, (int)E.size()){
        event e = E[i];
        if(e.f == 1){
            int fa = find_available(e.c);
            rec[fa] = e.c;
            used[fa] = true;
        }
        else if(e.f == 0){
            int fr = find_recording(e.c);
            rec[fr] = e.c + 100;
        }
        else{
            int fr = find_recording(e.c + 100);
            if(fr >= 0) rec[fr] = -1;
        }
    }

    int res = 0;
    rep(i, c){
        if(used[i]) res++;
    }
    cout << res << endl;
}