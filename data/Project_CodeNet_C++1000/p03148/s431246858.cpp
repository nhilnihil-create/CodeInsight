#include <bits/stdc++.h>
using namespace std;
int N,Q;


int main()
{
    
    cin >> N >> Q;
   
    vector<vector<long>> data(N);
    //データ入れ
    for(int i=0;i<N;i++)
    {
        int a;
        long b;
        cin >> a;
        cin >> b;
        data[a-1].push_back(b);
    }
    for(int i=0;i<N;i++)
    {
        if(data[i].size() == 0)
        {
            data[i].push_back(INT_MIN);
        }
        else
        {
            sort(data[i].begin(),data[i].end(),std::greater<long>());
        }
            
    }
    
    //sort
    sort(data.begin(),data.end(),std::greater<vector<long>>());
    
    vector<pair<long,int>> check; //おいしさ、種類の順
    int p = N;
   
    for(int i=0;i<N;i++)
    {
        if(data[i][0] <0)
        {
            p = i;
            break;
        }
        else
        {
            for(int j = 0;j<data[i].size();j++)
            {
                check.push_back(make_pair(data[i][j],i));
            }
        }
    }
    
    sort(check.begin(),check.end());
    reverse(check.begin(),check.end());
    
    vector<long> ans(Q,0);
    vector<int> used(p,0);
    
    long tt=0;
    for(int i = 0;i<Q;i++)
    {
        tt += check[i].first;
        used[check[i].second]++;
    }
    int kx = 0;
    for(int i = 0;i<p;i++)
    {
        if(used[i] > 0)
        {
            kx++;
        }
    }
    
    ans[kx-1] = tt + (long)kx*(long)kx;
    vector<bool> nonu(Q,true);
    
    for(int i = kx;i<p;i++)
    {
        long temp = 0;
        for(int j = 0;j<Q;j++)
        {
            if(used[check[Q-j-1].second] > 1 && nonu[Q-j-1])
            {
                used[check[Q-j-1].second]--;
                temp =check[Q-j-1].first;
                nonu[Q-j-1] = false;
                break;
            }
        }
        if(temp == 0)
        {
            break;
        }
        long temp2 = 0;
        for(int j = Q;j<N;j++)
        {
            if(used[check[j].second] == 0)
            {
                used[check[j].second]++;
                temp2 = check[j].first;
                break;
            }
        }
        ans[i] = ans[i-1] - temp + temp2 + 2*i + 1;
        
    }
    
    sort(ans.begin(),ans.end(),std::greater<long>());
    
    cout << ans[0] << endl;
    
    return 0;
    
}

    
    /* vector<pair<long,int>> check;
    vector<long> monn;
    int MAXI = N;
    int count = 0;
    int MINI = 0;
    bool mmm = false;
    for(int i=0;i<N;i++)
    {
        if(data[i][0] <0)
        {
            MAXI = i;
            break;
        }
        else
        {
            data[i][0] += 2*i+1;
            monn.push_back(data[i][0]);
            for(int j = 1;j<data[i].size();j++)
            {
                check.push_back(make_pair(data[i][j],i));
                count++;
            }
            if(count >= Q && !mmm)
            {
                MINI = i;
                mmm = true;
            }
            
        }
        
    }
    
    // monn:最初に入れるやつ
    // check それ以外の要素
    // MINI はじめてQ以上になったときの種類の数
    // MAXI 何種類あるか
    
    sort(check.begin(),check.end());
    reverse(check.begin(),check.end());
    
    vector<long> ans(MAXI - MINI,0);
    vector<int> a(MAXI - MINI,0);
    ans[0] = monn[0];
    a[0] = 1;
    
    for(int i = 1;i<MAXI-MINI;i++)
    {
        ans[i] = ans[i-1] + monn[i];
        a[i] = i+1;
    }
    
    
    for(int i = 0;i<N;i++)
    {
        for(int j = MAXI-1;j>=MINI;j--)
        {
            if(a[j-MINI] == Q)
            {
                MAXI--;
                continue;
            }
            if(check[i].second <= j )
            {
                ans[j -MINI] += check[i].first;
                a[j- MINI]++;
            }
        }
    }
    
    sort(ans.begin(),ans.end(),std::greater<long>());

    cout << ans[0] << endl;
   
    */
 