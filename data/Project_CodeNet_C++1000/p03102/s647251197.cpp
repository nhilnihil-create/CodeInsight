    #include<iostream>
    #include<vector>
    #include<math.h>
    #include<bits/stdc++.h>
     
    using namespace std;
     
    int main()
    {
        int n, m, c, count = 0;
        vector<int> bv;
        vector<vector<int>> av;

        cin >> n >> m >> c;

        for(int i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            bv.push_back(x);
        }

        for(int i = 0; i < n; i++)
        {
          av.push_back(vector<int>());
          
          for(int j = 0; j < m; j++)
          {
              int x;
              cin >> x;
              av[i].push_back(x);
          }
        }

        for(int i = 0; i < n; i++)
        {
            int total = 0;

            for(int j = 0; j < m; j++)
            {
                total = total + av[i][j]*bv[j];
            }

            if(total + c > 0)
                count++;
        }

        cout << count;
    }