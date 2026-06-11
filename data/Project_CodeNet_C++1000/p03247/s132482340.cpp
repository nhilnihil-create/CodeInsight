#include<bits/stdc++.h>
using namespace std;
long long x[100009],y[100009];
long long use[1000];
char mp[4] = {'R','D','L','U'};
int main()
{
  long long N,M,i,j,k = 0,now = 1;
  vector<long long> temp;
  cin >> N;
  for(i = 0;i < N;i++)
  {
    cin >>x[i] >> y[i];
    if((x[i] + y[i]) % 2 == 0)
    {
      k++;
    }
  }
  if(k != N && k != 0)
  {
    cout << -1 <<endl;
    return 0;
  }
  cout << 40 <<endl;
  now = 1;
  if(k == N)
  {
    use[0] = 1;
    use[1] = 1;
    for(i = 0;i < N;i++)
    {
      x[i]--;
    }
  }
  else
  {
    use[0] = 1;
    use[1] = 2;
  }
  cout << use[0] << " " << use[1] << " ";
  for(i = 2;i < 40;i++)
  {
    use[i] = use[i-1]*2;
    cout << use[i] << " ";
  }
  cout <<endl;
  for(i = 0;i < N;i++)
  {
    temp.clear();
    for(j = 39;j > 0;j--)
    {
      if(abs(x[i]) > abs(y[i]))
      {
        if(x[i] > 0)
        {
          temp.push_back(2);
          x[i] -= use[j];
        }
        else
        {
          temp.push_back(0);
          x[i] += use[j];
        }
      }
      else
      {
        if(y[i] > 0)
        {
          temp.push_back(1);
          y[i] -= use[j];
        }
        else
        {
          temp.push_back(3);
          y[i] += use[j];
        }
      }
    }
    if(k == N)
    {
      temp.push_back(2);
    }
    else
    {
      if(abs(x[i]) > abs(y[i]))
      {
        if(x[i] > 0)
        {
          temp.push_back(2);
        }
        else
        {
          temp.push_back(0);
        }
      }
      else
      {
        if(y[i] > 0)
        {
          temp.push_back(1);
        }
        else
        {
          temp.push_back(3);
        }
      }
    }
    for(j = temp.size()-1;j >= 0;j--)
    {
      cout << mp[(temp[j]+2) % 4];
    }
    cout << endl;
  }
}
