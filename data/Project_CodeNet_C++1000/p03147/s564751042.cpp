#include<iostream>
#include<vector>
using namespace std;

// 前から順に必要水やり回数を減らす
void mizuyari(int kaisu[], int sta, int end) {
  for(int i = sta; i < end; i++) {
    if(kaisu[i] == 0) {
      break;
    }
    kaisu[i] = kaisu[i] - 1;
  }

  return;
}

// 前から順に最初にゼロでない花を見つける
int get_not_zero(int kaisu[], int sta, int end) {
  for(int i = sta; i < end; i++) {
    if(kaisu[i] != 0) {
      return i;
    }
  }
  return end;
}


int main(void)
{
    int n;
  	cin >> n;
	
  	int kaisu[n];
  
  for(int i = 0; i < n; i++) {
    cin >> kaisu[i];
  }	  

  int num = 0;
  int sta = 0;

  while(1) {
    sta = get_not_zero(kaisu, sta, n);
    if(sta == n) {
      break;
    }
    num++;
    mizuyari(kaisu, sta, n);
  }

  cout << num;
    return 0;
}
