#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> datas;
  
  for(int i = 0; i < N; i++)
  {
    int num;
    cin >> num;
    datas.push_back(num);
  }
  sort(datas.begin(), datas.end());
  
  int sum = 0;
  for(int i = 0; i < N - 1; i++)
  {
	sum += datas[i];
    if(sum > datas[N-1])
    {
      cout << "Yes" << endl;
      return 0;
    }
  }
  
  cout << "No" << endl;
  return 0;
}