#include <iostream>
#include <vector>
int main()
{
    //入力
    int n, m;
    std::cin >> n >> m;
    std::vector<int> k(m);
    std::vector<std::vector<int>> s(m);
    std::vector<int> num(m);
    for (int i = 0; i < m; i++)
    {
        std::cin >> k[i];
        for (int j = 0; j < k[i]; j++)
        {
            int a;
            std::cin >> a;
            s[i].push_back(a);
        }
    }

    std::vector<int> p(m);
    for (int i = 0; i < m; i++)
    {
        std::cin >> p[i];
    }
 /* for(int i=0;i<m;i++){
    std::cout<<k[i]<<std::endl;
    for(int j=0;j<s[i].size();j++){
      std::cout<<s[i][j]<<" ";
    }
    std::cout<<std::endl;
    std::cout<<p[i]<<std::endl;
  }*/
    int count = 0;
    int ans = 0;
  int on=0;
    //解答

    for (int bit = 0; bit < (1 << n); bit++){
        count = 0;
      on=0;
            for (int i = 0; i < m; i++){
              on=0;
              //std::cout<<on<<std::endl;
              for(int j=0;j<s[i].size();j++){
                int b=s[i][j]-1;
                if (bit & (1 << b)){
                  on++;
                }
              }
                if (on % 2 == p[i])count++;
            }
        if (count == m)
            ans++;
    }
    std::cout << ans << std::endl;
    return 0;
}