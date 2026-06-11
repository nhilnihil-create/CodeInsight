#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool check (string s){
  int n = s.length();
  if (n%2==1){
    return false;
  }
  else {
    return (s.substr(0,n/2-1)==s.substr(n/2));
  }
}

int choise_sort (int n, int a[]){
  int index;
  for (int i=0; i<n-1; i++){
    int min = a[i], num;
    for (int j=i; j<n-1; j++){
      if (a[j+1]<min){
        min = a[j+1];
        num = j+1;
      }
    }
    index = a[i];
    a[i] = min;
    a[num] = index;
  }
}

int main(){
  int n, k;
  cin >> n >> k;

  vector<int> a(n), b(200100);
  for (int i=0; i<=200000; i++){
    b.at(i) = 0;
  }
  for (int i=0; i<n; i++){
    cin >> a.at(i);
    b.at(a.at(i))++;
  }

  sort(b.begin(),b.end());
  reverse(b.begin(),b.end());

  int sum = 0;
  for (int i=0; i<k; i++){
    sum += b.at(i);
  }

  cout << n - sum << endl;
}
