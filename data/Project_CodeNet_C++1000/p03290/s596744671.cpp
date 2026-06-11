//C - All Green

#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
  int D,G; //大問題数、目標点
  std::cin >> D >> G;  
  int p[D],c[D];
  for(int i = 0; i < D; i++) std::cin >> p[i] >> c[i];
  
  //入力確認
  //std::cout << "D:\t" << D << std::endl;
  //std::cout << "G:\t" << D << std::endl;
  //for(int i = 0; i < D; i++) std::cout << p[i] << "\t" << c[i] << std::endl;
  //入力確認

  long int res = D*100; //とりあえず大きな数値を入れる。あとで比較するため。
  for(int bit = 0; bit < (1<<D); bit++) //bit全探索、2^D通りを調べる
  {
    long int sumScore = 0;
    long int cnt = 0;
    for(int i = 0; i < D; i++) //大問ごとに調べる。
    {
      if(bit & (1<<i)) //フィルターみたいな役割
      {
        sumScore += (i + 1)*100*p[i] + c[i]; //大問のうち全部解いた場合のスコア
        cnt += p[i];
      }
    }      
    //目標点Gを超えた場合
    if (sumScore >= G) res = std::min(res, cnt); //問題数が少ない方を格納していく
    //目標点Gに到達していない場合
    else
    {
      for (int i = D - 1; i >= 0; i--)
      //for (int i = 0; i < D; i++)
      {
        if (bit & (1<<i)) continue;
        
        //完答せずに途中までに
        for (int j = 0; j < p[i]; j++)
        {
          if (sumScore >= G) break;
          sumScore += 100 * (i+1);
          ++cnt;
        }
      }
      
      res = std::min(res, cnt);
    }
  }

  std::cout << res;
  return 0;
}