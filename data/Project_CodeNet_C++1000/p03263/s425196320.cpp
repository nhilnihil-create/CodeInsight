#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
//using P =pair<int,int>;
//int dy[4] = {-1,0,1,0};
//int dx[4] = {0,-1,0,1};

int main()
{
    int H,W;
    cin >>H >> W;
    
    Graph data(H,vector<int>(W));
    Graph c(H,vector<int>(W));
    
    int count = 0;
    for(int i=0;i<H;i++)
    {
        for(int j=0;j<W;j++)
        {
            cin >> data[i][j];
            c[i][j] = data[i][j]%2;
            if(c[i][j] == 1)
            {
                count ++;
            }
        }
    }
    
    int t = 0;
    int j=0;
    int N = 0;
    int temp = count;
    for(int i=0;i<H;i++)
    {
        if(temp < 2) break;
        if(i%2 == 0)
        {
            while(j < W-1)
            {
                if(temp < 2) break;
                if(c[i][j] == 1)
                {
                    t++;
                    if(t==2)
                    {
                        temp -=2;
                        t = 0;
                    }
                }
                
                if(t==1)
                {
                    N++;
                }
                j++;
            }
            if(temp < 2) break;
            if(c[i][j] == 1)
            {
                t++;
                if(t==2)
                {
                    temp -=2;
                    t = 0;
                }
            }
            
            if(t==1)
            {
                N++;
            }
            //j++;
        }
        else
        {
            while(j >0)
            {
                if(temp < 2) break;
                if(c[i][j] == 1)
                {
                    t++;
                    if(t==2)
                    {
                        temp -=2;
                        t = 0;
                    }
                }
                
                if(t==1)
                {
                    N++;
                }
                j--;
            }
            if(temp < 2) break;
            if(c[i][j] == 1)
            {
                t++;
                if(t==2)
                {
                    temp -=2;
                    t = 0;
                }
            }
            
            if(t==1)
            {
                N++;
            }
            //j++;
        }
    }
    
    cout << N << endl;
    t=0;
    j=0;
    for(int i=0;i<H;i++)
    {
        if(count < 2) break;
        if(i%2 == 0)
        {
            while(j < W-1)
            {
                if(count < 2) break;
                if(c[i][j] == 1)
                {
                    t++;
                    if(t==2)
                    {
                        count -=2;
                        t = 0;
                    }
                }
                
                if(t==1)
                {
                    cout << i+1 <<" " <<  j+1 << " ";
                    cout << i+1 <<" " <<  j+2 << endl;
                }
                j++;
            }
            if(count < 2) break;
            if(c[i][j] == 1)
            {
                t++;
                if(t==2)
                {
                    count -=2;
                    t = 0;
                }
            }
            
            if(t==1)
            {
                cout << i+1 <<" " <<  j+1 << " ";
                cout << i+2 <<" " <<  j+1 << endl;
            }
            //i++;
        }
        else
        {
            while(j >0)
            {
                if(count < 2) break;
                if(c[i][j] == 1)
                {
                    t++;
                    if(t==2)
                    {
                        count -=2;
                        t = 0;
                    }
                }
                
                if(t==1)
                {
                    cout << i+1 <<" " <<  j+1 << " ";
                    cout << i+1 <<" " <<  j << endl;
                }
                j--;
            }
            if(count < 2) break;
            if(c[i][j] == 1)
            {
                t++;
                if(t==2)
                {
                    count -=2;
                    t = 0;
                }
            }
            
            if(t==1)
            {
                cout << i+1 <<" " <<  j+1 << " ";
                cout << i+2 <<" " <<  j+1 << endl;
            }
            //++;
        }
    }
    
    
    
    return 0;
}



/*

int main()
{
    /*
    int H,W,K;
    cin >> H >> W >> K;
    
    vector<string> data;
    for(int i=0;i<H;i++)
    {
        cin >> data[i];
    }
 
    
    string s;
    int k;
    cin >> s;
    cin >> k;
    long long temp = k;
    int t = (int)s.size();
    
    for(int i = 0;i<t-1;i++)
    {
        if(temp > 122 || s[i] + temp > 122)
        {
            temp -= (123 - s[i]);
            s[i] = 'a';
        }
    }
    
    long long px = (long long)s[t-1];
    px += temp;
    
    px = (px - 97) % 26 + 97;
    s[t-1] = (char)px;
    
    cout << s << endl;
    
    return 0;
}

*/