#include <iostream>
#include <vector>

using namespace std;

/*
再帰関数での全探索
bit全探索(2^n通り)
*/

void many_equals();

void train_ticket();


int main()
{
  //many_equals();
  train_ticket();
}


void many_equals()
{
  string S;
  cin >> S;
  vector<int> a(S.size());

  for (int i = 0; i < S.size(); ++i)
  {
    a[i] = S[i] - '0';
  }

  cout << (1 << (S.size() - 1)) << "\n";;

  long long int n_sum = 0;
  for (int i = 0; i < 1 << (S.size() - 1); ++i)
  {
    //cout << i << "\n";
    long long int tmp = a[0];
    for (int p = 0; p < S.size() - 1; ++p)
    {
      //p left shift先にあれば
      if (i & 1 << p)
      {
        n_sum += tmp;
        tmp = a[p + 1];
      }
      else
      {
        tmp = tmp * 10 + a[p + 1];
      }
    }
    n_sum += tmp;
  }

  cout << n_sum << "\n";
}

void train_ticket()
{
  string abcd;
  cin >> abcd;
  vector<int> a(abcd.size());
  for (int i = 0; i < abcd.size(); ++i)
  {
    a[i] = abcd[i] - '0';
  }

  vector<char> sign(3);

  for (int i = 0; i < 1 << (abcd.size() - 1); ++i)
  {
    int v_sum = a[0];
    for (int j = 0; j < abcd.size() - 1; ++j)
    {
      if (i & 1 << j)
      {
        v_sum += a[j + 1];
        sign[j] = '+';
      }
      else
      {
        v_sum -= a[j + 1];
        sign[j] = '-';
      }
    }
    //iの位置は+,それ以外は-を行う判定
    if (v_sum == 7)
    {
      for (int k = 0; k < 3; ++k)
      {
        cout << abcd[k] << sign[k];
      }
      cout << abcd[3] << "=7\n";

      return;
    }
  }
}