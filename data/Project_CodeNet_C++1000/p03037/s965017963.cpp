#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N,M,cnt=0;
    cin >> N >> M;
    vector<bool> c(N,true);

    int tmpl = 1;
    int tmpr = N;

    for(int i=0; i<M; i++){
        int l,r;
        cin >> l >> r;

        if(l > tmpl){
            for(int j=tmpl-1; j<l-1; j++){
                c.at(j) = false;     
            }
            tmpl = l;
        }
        if(r < tmpr){
            for(int j=r; j<tmpr; j++){
                c.at(j) = false;       
            }
            tmpr = r;
        }

        /*for(int j=0; j<N; j++)
            cout << c.at(j) <<flush;
        cout << endl; */
    }

    for(int i=0; i<N; i++){
        if(c.at(i) == true)
            cnt++;
    }

    cout << cnt << endl;

    return 0;
}