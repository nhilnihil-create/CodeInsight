#include <bits/stdc++.h>
using namespace std;
const int MXN = 55555;
bool Seive[MXN];
queue<int64_t> Primes;

void initSeive(int64_t N)
{
  for (int i = 0; i <= N; i++)
    Seive[i] = true;
}

bool isPrime(int64_t x)
{
  return Seive[x];
}

void makeSeive(int64_t N)
{
  initSeive(N);
  Seive[0] = Seive[1] = false;
  for (int64_t i = 2; i <= N; i++)
  {
    if (!isPrime(i))
      continue;
    Primes.emplace(i);
    for (int64_t j = 2; i * j <= N; j++)
    {
      Seive[i * j] = false;
    }
  }
}

int main()
{
  int N;
  cin >> N;
  makeSeive(MXN);
  vector<int64_t> A;
  while (A.size() < N)
  {
    if (Primes.front() % 5 == 1)
    {
      A.push_back(Primes.front());
    }
    Primes.pop();
  }
  for (int i = 0; i < A.size(); i++)
  {
    cout << A.at(i);
    if (i != A.size() - 1)
      cout << ' ';
  }
  cout << endl;
}