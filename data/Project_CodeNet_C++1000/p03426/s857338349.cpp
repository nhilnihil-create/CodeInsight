#include <bits/stdc++.h>
using namespace std;
//using Graph = vector<vector<int>>;
using P = pair<int,int>;
//int dy[4] = {-1,0,1,0};
//int dx[4] = {0,-1,0,1};


int main()
{
    int H,W,D;
    cin >> H >> W >> D;
    
    int size = H*W;
    
    vector<int> I(size),J(size);
    for(int i=0;i<H;i++)
    {
        for(int j=0;j<W;j++)
        {
            int t;
            cin >> t;
            t--;
            I[t] = i;
            J[t] = j;
        }
    }
    
    vector<int> data(size);
    
    for(int i=0;i<size;i++)
    {
        if(i-D<0)
        {
            data[i] = 0;
            continue;
        }
        data[i] = abs(I[i] - I[i-D]) + abs(J[i] - J[i-D])  + data[i-D];
    }
    
    int Q;
    cin >> Q;
    vector<long long> ans(Q);
    for(int i=0;i<Q;i++)
    {
        int l,r;
        cin >> l >> r;
        
        l--;
        r--;
        
        cout << data[r] - data[l] << endl;
        
    }
    return 0;
}


/*
int main()
{
    int N;
    cin >> N;
    
 
 int ans;
 cout << ans << endl;
    return 0;
}
*/