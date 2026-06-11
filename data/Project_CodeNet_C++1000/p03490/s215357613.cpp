#include <bits/stdc++.h>

using namespace std;

int m[32005][4005];
vector <int> p;

bool solve(int val, int ind){
    if(ind==p.size()){
        return (val==0);
    }
    int mval=val+16002;
    //assert(!(mval<0 || mval >= 32005 || ind >= 2005));
    if(m[mval][ind]!=-1){
        return m[mval][ind];
    }
    return m[mval][ind]=(solve(val-p[ind],ind+1) || solve(val+p[ind],ind+1));
}


int main(){
    string s;
    int x,y,n;
    cin >> s >> x >> y;
    s.push_back('T');
    n=s.size();
    vector <int> a[2];
    bool fi=1;
    int dir=0,steps=0;
    for(int i=0;i<n;i++){
        if(s[i]=='T'){
            if(fi){
                x-=steps;
                fi=0;
            }
            else{
                a[dir].push_back(steps);
            }
            dir=1-dir;
            steps=0;
        }
        else{
            steps++;
        }
    }
    memset(m,-1,sizeof(m));
    p=a[0];
    if(!solve(x,0)){
        cout << "No" << endl;
        return 0;
    }
    memset(m,-1,sizeof(m));
    p=a[1];
    if(!solve(y,0)){
        cout << "No" << endl;
        return 0;
    }
    else{
        cout << "Yes" << endl;
    }
    return 0;
}
