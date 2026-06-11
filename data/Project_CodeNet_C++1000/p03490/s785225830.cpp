    #include<bits/stdc++.h>
    #define rep(i,a,b) for(int i=int(a);i<int(b);++i)
    using namespace std;
    typedef long long ll;
    int INF = (1LL << 30) - 1;
    int MOD = 1e9+7;
    main(){
        string S;
        cin >> S;
        int X,Y;
        cin >> X >> Y;
        vector<int> V(1);
        int idx = 0;
        for(auto c:S){
            if(c == 'F')V[idx]++;
            else {
                V.push_back(0);
                idx++;
            }
        }
        //for(auto i:V)cout << i << " ";cout << endl;
        map<int,int> mpx, mpy;
        mpx[V[0]] = 0;
        mpy[0] = -1;
        rep(i,1,V.size()){
            if(i % 2 == 0){
                vector<int> v;
                for(auto p:mpx){
                    if(p.second == i-2)v.push_back(p.first);
                }
                for(auto j:v){
                    mpx[j + V[i]] = i;
                    mpx[j - V[i]] = i;
                }
            }else{
                vector<int> v;
                for(auto p:mpy){
                    if(p.second == i-2)v.push_back(p.first);
                }
                for(auto j:v){
                    mpy[j + V[i]] = i;
                    mpy[j - V[i]] = i;
                }
            }
        }
        bool findx = 0, findy = 0;
        for(auto p:mpx){
            //cout  << p.first << "," << p.second << " ";
            if(p.second == V.size() - (V.size() % 2 ? 1 : 2)){
                if(p.first == X)findx = 1;
            }
        }//cout << endl;
        for(auto p:mpy){
            //cout  << p.first << "," << p.second << " ";
            if(p.second == V.size() - (V.size() % 2 ? 2 : 1)){
                if(p.first == Y)findy = 1;
            }
        }//cout << endl;
        if(findx && findy)cout << "Yes" << endl;
        else cout << "No" << endl;
    }
